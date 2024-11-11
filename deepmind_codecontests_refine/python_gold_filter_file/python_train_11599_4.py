n=input()
n=n.replace('144', '*') 
n=n.replace('14', '*') 
n=n.replace('1', '*') 
n=set(n)
if(len(n)!=1):
    print("NO")
else:
    for i in n:
        if(i!='*'):
            print("NO")
        else:
            print("YES")