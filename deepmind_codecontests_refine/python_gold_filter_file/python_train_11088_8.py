s1=int(input())
s2=input()
d=1
et=s2[0]
p=0
tp="2"
for i in range(1,s1):
    if s2[i]!=et:
        d=d+1
        et=s2[i]
    if s2[i]==s2[i-1] and tp!=s2[i]:
        p=p+1
        #tp=s2[i]
    #if s2[i]!=tp:
     #   tp=2
if p==0:
    print(d)
elif p==1:
    print (d+1)
else:
    print (d+2)
