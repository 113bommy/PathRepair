n=input()
r=(1<<len(n))-2
for i in range(len(n))[::-1]:
    if(n[i]=='7'):
        r+=1<<(len(n)-i-1)
print(r+1)