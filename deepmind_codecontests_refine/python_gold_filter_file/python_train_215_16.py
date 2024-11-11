n,s = [ int(i) for i in input().split()]
a = [ int(i) for i in input().split()]
a.sort();
o = 0;
if a[-(n//2)-1] < s:
  for i in range (n-1,n//2-1,-1):
    if a[i] < s:
        o = o+ s-a[i];
else:
  for i in range (n//2+1):
      if a[i] > s:
          o = o- (s-a[i]);  
print (o)