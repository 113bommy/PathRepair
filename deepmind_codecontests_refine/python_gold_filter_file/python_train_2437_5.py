n=int(input());l=list(map(int,input().split()));l.sort()
l2=l[:len(l)//2];l1=l[len(l)//2:]
print(l1[-1],*l2[1:],*l1[:-1],l2[0])
