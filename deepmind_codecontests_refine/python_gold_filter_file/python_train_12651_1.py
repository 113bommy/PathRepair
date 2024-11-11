n = int(input())
A = input().split()
max = 0
max_i = A[0]
Likes = dict()
for a in A:
    if a not in Likes:
        Likes[a] = 1
    else:
        Likes[a] += 1
        if Likes.get(a) > max:
            max = Likes.get(a)
            max_i = int(a)
print(max_i)