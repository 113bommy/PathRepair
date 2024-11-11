requests_number = int(input())
original_names = dict()
incumbent_names = dict()

for i in range(requests_number):
    old, new = input().rstrip().split(' ')
    if old not in incumbent_names:
        original_names[old] = new
        incumbent_names[new] = old
    else:
        incumbent_names[new] = incumbent_names[old]
        original_names[incumbent_names[old]] = new
        del incumbent_names[old]


print(len(original_names))
for i in original_names:
    print("{} {}".format(i, original_names[i]))
