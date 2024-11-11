n=eval(input())
t=n
l=[0]
for i in range(2,int(n**0.5)+1):
    while n%i==0:
        n/=i
        l.append(int(i))
if n>1 and n!=t:
    l.append(int(n))
if (len(l)!=3):
    try:
        print("1\n{}".format(l[1]*l[2]))
    except:
        print("1\n0")
else:
    print(2)
