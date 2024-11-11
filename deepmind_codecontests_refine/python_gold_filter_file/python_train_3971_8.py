a=input()
b=input()
v=[ 'a', 'e', 'i', 'o','u']

if len(a)==len(b):
    u=0
    for k in range(len(a)):
        if a[k] in v and b[k] in v:
            pass
        elif a[k] not in v and b[k] not in v:
            pass
        else:
            print('No')
            u+=1
            break
        
    if u==0:
        print('Yes')
    
else:
    print('No')
