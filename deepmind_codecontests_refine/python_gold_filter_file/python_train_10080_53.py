s=input()
k=int(input())
str=[]
p=1
for i in range(k):
    for j in range(0,len(s)-i):
        str.append(s[j:j+i+1])
str=list(set(str))
str.sort()
print(str[k-1])