n = int(input())
guys = ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"]

len_group = len(guys)
count_clones = 1
total_prev = 0
total = len_group

while total < n:
    count_clones *= 2
    total_prev = total
    total += len_group * count_clones

num_in_group = (n - total_prev) - 1
print(guys[num_in_group // count_clones])