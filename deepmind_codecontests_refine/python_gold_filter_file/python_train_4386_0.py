n=int(input())
s=input()
ind=n-1
for i in range(n-1):
    if s[i]>s[i+1]:
        ind=i
        break

s=s[:ind]+s[ind+1:]
print(s)
    
