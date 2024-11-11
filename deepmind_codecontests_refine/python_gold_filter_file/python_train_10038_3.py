# input
n, m = map(int, input().rstrip().split())
n_array, m_array = list(map(int, input().rstrip().split())),list(map(int, input().rstrip().split()))
a, b = 0,0
#Slices through second line (requirements for the complexity of the problems in a good round), if the problem's
#complexity match with the prepared problem's complexity then move to the next question.
while (a<n) & (b<m):

    if n_array[a] <= m_array[b]:
        a += 1
    b += 1

print(n-a)