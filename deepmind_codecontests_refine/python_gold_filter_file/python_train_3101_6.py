A,B,C=map(int,input().split())
X=C-A-B
print('Yes' if X>0 and 4*A*B<X**2 else 'No')
