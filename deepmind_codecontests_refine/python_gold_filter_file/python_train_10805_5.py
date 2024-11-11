import sys
input = sys.stdin.readline #高速化期待
from collections import deque

def main():
    N = int(input())
    A = [deque()] + [deque( map( int, input().split())) for _ in range(N)]
    NOW = [0]*(N+1)
    Days = [0]*(N+1)
    q = deque( [ i+1 for i in range(N)])
    while q:
      i = q.popleft()
      if not A[i]:
        continue
      
      a = A[i].popleft()
      
      if NOW[a] == i:
        NOW[a] = 0
        Days[a] = Days[i] = max((Days[i], Days[a])) + 1
        q.append(i)
        q.append(a)
      else:
        NOW[i] = a
    for i in range(N+1):
      if A[i]:
        print(-1)
        return
    print(max(Days))
if __name__ == '__main__':
    main()