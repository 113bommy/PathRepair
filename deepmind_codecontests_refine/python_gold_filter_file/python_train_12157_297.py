D,T,S = map(int, input().split())
print('Yes' if (D+S-1)//S <= T else 'No')