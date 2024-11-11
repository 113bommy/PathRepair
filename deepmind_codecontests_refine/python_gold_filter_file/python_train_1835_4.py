n=int(input())
s=input()
i=0
letter=[]
num=[]
while i<n :
    if s[i].islower()and letter.count(s[i])==0 :
        letter.append(s[i])
    if s[i].isupper()or i==n-1:
        num.append(len(letter))
        letter=[]
    i+=1
if len(num)!=0:
    print(max(num))
else :
    print("0")
