n, k = map(int, input().split())
a = list(map(int, input().split()))

min_residue = n
box_type = 0
box_number = 0

for i in range(k):
    if n % a[i] <= min_residue:
        min_residue = n % a[i]
        box_type = i + 1
        box_number = n // a[i]


print(box_type, box_number)
