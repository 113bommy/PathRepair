n=int(input())
s=input()
for i in range(n-1):
    if s[i]>s[i+1]:
        print(s[0:i]+s[i+1:n])
        exit()
print(s[0:n-1])