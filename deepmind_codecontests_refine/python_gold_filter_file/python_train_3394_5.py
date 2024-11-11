e = int(input().split(' ')[1])
l = [int(i) for i in input().split(' ')]
b = True
a=set()
cnt=[0 for i in range(1000005)]
for i in range (len(l)):
    cnt[l[i]]+=1
    if l[i] == e:
        b = False;
        c=list()
        for j in a:
            if cnt[j]<cnt[e]:
                c.append(j)
        for j in range(len(c)):
            a.remove(c[j])
    if b == True and cnt[l[i]]==1:
        a.add(l[i])
if len(a)==0 :
  print("-1")
else:
  print(a.pop())