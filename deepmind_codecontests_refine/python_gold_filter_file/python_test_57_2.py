T = int(input())
 
for t in range(T):
    s, n, k = map(int, input().split())
    
    if s == k:
        print('YES')
        continue
    
    s -= n;
    if (s >= n // k * k):
        print("NO");
    else:
        print("YES");