def add(elements, to_add):
    if to_add not in elements:
        elements[to_add] = 0
    elements[to_add] += 1
 
 
def remove(elements, to_remove):
    elements[to_remove] -= 1
    if elements[to_remove] == 0:
        del elements[to_remove]
 
 
_, limit = [int(i) for i in input().split()]
arr = [int(i) for i in input().split()]
 
longest_good = 0
good_seg = [-1, -1]
 
left = 0
elements = {}
for right in range(len(arr)):
    add(elements, arr[right])
    while len(elements) > limit:
        remove(elements, arr[left])
        left += 1
    if right - left + 1 > longest_good:
        longest_good = right - left + 1
        good_seg = [left + 1, right + 1]
print(good_seg[0], good_seg[1])
