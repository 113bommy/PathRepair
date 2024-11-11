




n = int(input())
heights = [int(i) for i in input().split()]

maxid = 0
#print(f"maxid: {maxid}")
minid = len(heights) - 1
#print(f"minid: {minid}")
seconds = 0

#iterate over the list
for i in range(len(heights)):
	#print(f"i: {i}")
	#find the maxid closest to index 0
	if heights[i] > heights[maxid]:
		maxid = i
		#print(f"maxid: {maxid}")
	#find the minid closest to last index
	if heights[i] <= heights[minid]:
		minid = i
		#print(f"minid: {minid}")
#seconds = the distance of the max from the beginning plus
#the distance of the min from the end
seconds = maxid + (len(heights) - 1 - minid)
if minid < maxid:
	seconds -= 1
print(seconds)

