h,w=map(int,input().split())
a,l=[list(input())for i in range(h)],[0]*26
for i in a:
 for j in i:l[ord(j)-97]+=1
o,t,f=(h//2)*(w//2),(h//2)*(w%2)+(w//2)*(h%2),(h%2)*(w%2)
for i in l:
 while o and i>3:o-=1;i-=4
 while t and i>1:t-=1;i-=2
 f-=i
print("Yes"if o==t==f==0else"No")
