n=int(input())-1
s=sorted(map(int,input().split()))
sp=(s[n]-s[0])*(s[2*n+1]-s[n+1])
for i in range(n+1):
   sp=min(sp,(s[n+i]-s[i])*(s[2*n+1]-s[0]))
print(sp)