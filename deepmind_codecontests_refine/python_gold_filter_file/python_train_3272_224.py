n=int(input())
e=[]
s=''
a = input().split()
a.sort(key=int)
for i in a:
    s+=str(i + ' ')
print(str(s))