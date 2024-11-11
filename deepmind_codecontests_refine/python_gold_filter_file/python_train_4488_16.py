para = list(map(int, input().split()))
n = int(para[0])
k = int(para[1])
s = input()
track = [0] * k

def even(track):    
    for i in range(len(track) - 1):
        if track[i] != track[i + 1]:
            return False
    return True

for i in s:
    track[ord(i) - 65] += 1
track = sorted(track)
#if even(track):
#    print((track[0] - 1) * len(track))
#else:
print(track[0] * len(track))