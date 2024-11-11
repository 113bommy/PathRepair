A, B, C = map(int, input().split())
print('Yes' if A-C>0 and C-B>0 or A-C<0 and C-B<0 else 'No')