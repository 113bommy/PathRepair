N = int(input())

print(' {}'.format(' '.join([str(c) for c in range(1, N + 1) 
  if c % 3 == 0 or '3' in str(c)])))