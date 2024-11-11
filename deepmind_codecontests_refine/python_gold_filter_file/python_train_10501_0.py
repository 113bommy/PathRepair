import sys
for e in sys.stdin:
 e=sorted(map(int,e.split(',')))
 print([['null','straight'][e[4]-e[0]==4 or e[0]*10==e[1]],'one pair','two pair','three card','full house',0,'four card'][sum(e.count(s)for s in e)//2-2])
