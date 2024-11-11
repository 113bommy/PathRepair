import math
m,f = map(int,input().split())
h_male = list(map(int,input().split()))
h_male = h_male[1:]
h_female = list(map(int,input().split()))
h_female = h_female[1:]
lcm = (m*f)//math.gcd(m,f)
for i in range(2*lcm):
    if (i%m) in h_male:
        if (i%f) not in h_female:
            h_female.append(i%f)
    elif (i%f) in h_female:
        if (i%m) not in h_male:
            h_male.append(i%m)
if((len(h_female)== f) and (len(h_male) == m)):
    print("Yes")
else:
    print("No")
