f = input().split()
n = int(f[0])
m = int(f[1])
a = int(f[2])
if (n) >= (a):
    answer1 = (n)/(a)
    if n%a==0:
        pass
    else:
        answer1 = (int(answer1)+1)
else:
    answer1=1
if (m) >= (a):
    answer2 = (m)/(a)
    if m%a==0:
        pass
    else:
        answer2 = (int(answer2)+1)
else:
    answer2=1
print(int(answer1*answer2))
