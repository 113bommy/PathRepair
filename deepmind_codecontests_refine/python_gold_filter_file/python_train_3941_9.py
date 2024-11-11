A,B,C=map(int,input().split())
print('YNeos'[(C<A)or(C>B)::2])