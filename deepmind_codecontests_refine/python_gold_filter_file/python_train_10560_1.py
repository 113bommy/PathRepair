import operator
input()
l = [[p,i,0] for i,p in enumerate (map(int,input().split()))]
l.sort()
t=0
for i in range(len(l)):l[i][2]=t%2;t+=1

l.sort(key = operator.itemgetter(1))

print (' '.join ([str(ll[2]) for ll in l]))