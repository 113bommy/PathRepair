s=input()
count=0
for i in range(len(s)//2):
    if s[i]!=s[len(s)-1-i]:
        count+=1
if count==0 and len(s)%2==0:
    print("NO")
elif count<=1:
    print("YES")
else:
    print("NO")
