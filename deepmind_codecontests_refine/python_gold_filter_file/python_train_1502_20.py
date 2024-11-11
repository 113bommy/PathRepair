st = input()
b = 0
s =0
c= 0
count = 0
for i in range(len(st)):
    if st[i] == "B":
       b+=1
    elif st[i] == "S":
       s+=1
    elif st[i] == "C":
        c += 1
 
aval =  list(map( int , input().split()))
prices = list(map(int ,input().split()))
rubies = int(input())
 
 
 
if b ==0 :
    aval[0] = 0
    prices[0] = 0
if s ==0 :
    aval[1] = 0
    prices[1] =0
if c ==0 :
    aval[2] = 0
    prices[2]=0
 
while (aval[0] >= b and aval[1] >= s and aval[2] >= c):
    aval[0] = aval[0] - b
    aval[1] = aval[1] - s
    aval[2] = aval[2] - c
    count += 1
 
 
while(rubies >= min(prices)):


    if aval[0] == aval[1]== aval[2] == 0 :
        count += rubies // (b*prices[0]+s*prices[1]+c*prices[2])
        print(count)

        exit()
    if aval[0] < b:
        rubies = rubies - (b - aval[0] )*prices[0]
        aval[0]= b
    if aval[1] < s:
        rubies = rubies - (s - aval[1] )*prices[1]
        aval[1] = s
    if aval[2] < c:
        rubies = rubies - (c - aval[2] )*prices[2]
        aval [2] = c


 
    aval[0] = aval[0] - b
    aval[1] = aval[1] - s
    aval[2] = aval[2] - c
    if(rubies >= 0 ) :
        count += 1
 
 
 
 
print (count)