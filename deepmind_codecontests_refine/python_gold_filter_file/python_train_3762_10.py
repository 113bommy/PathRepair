n=int(input())
s=input().split()
s=list(s)
for i in range(n):
    s[i]=int(s[i])
s.sort()
sum=0 
#print(*s)
for i in range(n//2):
    sum+=((s[i]) + s[n-1-i])**2
print(sum)
            
        