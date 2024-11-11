a=input()
s=0
p='aeiou'
c='13579'
for i in range(len(a)):
    if p.count(a[i])==1 or c.count(a[i])==1:
        s+=1
print(s)