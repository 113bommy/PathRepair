#sys.stdout=open("output.txt", 'w')
#sys.stdout.write("Yes" + '\n')
#from  sys import stdin
#input=stdin.readline
#a = sorted([(n, i) for i, n in enumerate(map(int, input().split()))])
# from collections import Counter
# import sys
#s="abcdefghijklmnopqrstuvwxyz"
#arr=sorted([(int(x),i) for i,x in enumerate(input().split())])
#n=int(input())
#n,k=map(int,input().split())
#arr=list(map(int,input().split()))
#arr=list(map(int,input().split
s = input()
st = "AEIOUY"
cnt = 0
m=0
for i in range(len(s)):
    if s[i] not in st:
        cnt += 1
        #print(cnt)
        if i==len(s)-1:
            m = max(m, cnt)
    else:
        m = max(m, cnt)
        cnt = 0

print(max(1,m+1))
