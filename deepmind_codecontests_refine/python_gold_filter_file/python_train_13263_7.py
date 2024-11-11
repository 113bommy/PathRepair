nums = [int(x) for x in input().split(",")]
counter = [0] * 1002
for num in nums:
    counter[num] += 1
start = -1
end = -1
result = []
for idx, count in enumerate(counter):
    if count > 0:
        if start == -1:
            start = idx
        else:
            end = idx
    else:
        if end == -1 and start != -1:
            result.append(str(start))
        elif start < end:
            result.append(str(start) + "-" + str(end))
        start = -1
        end = -1
print(",".join(result))