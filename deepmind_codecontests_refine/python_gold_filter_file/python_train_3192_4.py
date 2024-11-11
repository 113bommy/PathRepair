#from collections import Counter,defaultdict
#get= lambda : map(int,input().split())
import re
input()
s=input()
if re.findall('C{2,}|M{2,}|Y{2,}',s):
        print ("No")
        exit()
if s.startswith('?') or s.endswith('?'):
        print("Yes")
        exit()
s=' '+s+' '

l=0


for i,j in enumerate(s):
        if '?'==j:
                l+=1
        else:
                if l==1:
                        if  s[i-2]==s[i]:
                                print("Yes")
                                break 
                if l>=2:
                        print("Yes")
                        break
                l=0
else:
        print("No")
#http://codeforces.com/problemset/problem/957/A
