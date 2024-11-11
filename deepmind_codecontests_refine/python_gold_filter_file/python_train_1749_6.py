n , k = [ int(i) for i in input().split()]
s =input()
a =0
for i , ch in enumerate(s[1:] , 1):
  if ch == s[i-1]:
   	a+=1
print( min( n -1, a +2*k))
