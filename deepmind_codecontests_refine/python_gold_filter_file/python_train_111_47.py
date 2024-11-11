n = int(input())
m = list(map(int,input().split()))
r = 0
t = max(m)

for i in m:
    r+=t-i

if(sum(m)<r):
    print(t)
else:
    print(t+(sum(m)-r)//n+1)