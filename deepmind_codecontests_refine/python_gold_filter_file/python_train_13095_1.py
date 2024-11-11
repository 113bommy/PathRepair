n=int(input())
s=input()
t=0
for i in range(n-1):
    if s[i]!=s[i+1]:
        t+=1
print(t+1)