s1= input()
s2 = input()
l1=['a','e','i','o','u']
l2 = ['b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'x', 'z']
l3=list(s1)
l4 = list(s2)
flag=True
if(len(l3)!=len(l4)):
    flag=False
for i in range(min(len(l3),(len(l4)))):
    if(l3[i] in l1 and l4[i] in l2):
        flag=False
        break
    elif(l3[i] in l2 and l4[i] in l1):
        flag = False
        break
if(flag):
    print("Yes")
elif(flag==False):
    print("No")