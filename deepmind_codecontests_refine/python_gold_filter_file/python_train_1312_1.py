def add_up_array(arr, k, n):
    for i in range(1, n):
        arr[i] = arr[i] + arr[i - 1]
        if arr[i] > k:
            return "YES"
    return "NO"


n, k = map(int, input().split())
entrances = input()

added = set()
last_index = {}
doors_opened = [0] * (len(entrances) + 1)

for i in range(len(entrances)):
    last_index[entrances[i]] = i

for i, c in enumerate(entrances):
    if c not in added:
        doors_opened[i] += 1
        added.add(c)
    if i == last_index[c]:
        doors_opened[i + 1] -= 1

print(add_up_array(doors_opened, k, n))
