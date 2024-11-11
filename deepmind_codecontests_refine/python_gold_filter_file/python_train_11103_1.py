n=int(input())
str=input()
count=0
i=0
while i<=n-2:
    if str[i]=='U' and str[i+1]=='R' or str[i]=='R' and str[i+1]=='U':
        count+=1
        i+=1
    i+=1
print(n-count)