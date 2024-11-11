c=0
l='13579'
d='aiuoe'
s=input()
for i in s:
    if(i in l or i in d):
        c=c+1
print(c)
