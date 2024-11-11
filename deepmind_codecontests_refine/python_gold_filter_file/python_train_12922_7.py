n = int(input())
lst = list( map(int,input().split()) )

max_lst = sorted(lst, reverse=True)
max_lst.pop(0)

max_low = min(max_lst)
max_high = max(max_lst)
max_inst = max_high - max_low

min_lst = sorted(lst, reverse=False)
min_lst.pop(0)

min_low = min(min_lst)
min_high = max(min_lst)
min_inst = min_high - min_low

final_lst = [max_inst, min_inst]

print(min(final_lst))
