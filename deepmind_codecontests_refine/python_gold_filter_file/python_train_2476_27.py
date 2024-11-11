A, B, C, D = map(int, input().split())
print('Yes' if -(-C//B) <= -(-A//D) else 'No')