l = [int(input()) for _ in range(5)]
k = int(input())

print(':(' if l[-1] - l[0] > k else 'Yay!')
