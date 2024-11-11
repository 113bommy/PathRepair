s=input()
m=s[1:-1]
a=m.split(', ')
a.sort()
count=1
w='a'
if ''in a:
    print(0)
elif len(a)==1:
    print(1)
else:
    for i in range(1,len(a)):
       q=a[i]
       if q>w:
          count+=1
          w=a[i]
    print(count)