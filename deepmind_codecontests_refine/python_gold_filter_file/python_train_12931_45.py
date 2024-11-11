n, m = [int(i) for i in input().split()]
n_seq = input().split()
m_seq = input().split()
q = int(input())
for i in range(q):
    y = int(input())
    gapja_y = n_seq[y%n-1]+m_seq[y%m-1]
    print(gapja_y)