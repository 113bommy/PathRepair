#~ import io
#~ import sys

#~ test = '''3
#~ 5
#~ 2
#~ 1
#~ 3'''
#~ test = '''3
#~ 6
#~ 2
#~ 3
#~ 2'''
#~ test = '''2
#~ 5
#~ 5
#~ 10'''
#~ sys.stdin = io.StringIO(test)

n = int(input())
m = int(input())
a = []
for i in range(n):
   a.append(int(input()))

a.sort(reverse=True)
#~ print(a)
i = 0
while m>0:
   m -= a[i]
   i += 1
print(i)   
