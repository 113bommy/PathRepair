_,*l=open(0).read().split()
[print(i + 1)for i in sorted(range(len(l)//2),key=lambda i:(l[i*2],-int(l[i*2+1])))]