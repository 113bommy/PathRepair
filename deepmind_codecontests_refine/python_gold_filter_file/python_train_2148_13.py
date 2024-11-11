last_caffe = -1
cefes_count = int(input(""))
cafes_rating = input("").split(" ")

# x visits of n cafes with possible repeats
cafes_visited = {-1,} # use set
visited_cafes_count = 0
cafes_rating.reverse()
for x in cafes_rating:
#for i in reversed(range(cefes_count)):
    #x = int(cafes_rating[i])
    if not x in cafes_visited:
        cafes_visited.add(x)
        visited_cafes_count += 1
        last_caffe = x
    if visited_cafes_count == cefes_count:
        break
print(last_caffe)