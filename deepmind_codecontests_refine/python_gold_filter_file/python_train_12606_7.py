n, m = map(int, input().split())
songs = []

for _ in range(n):
    a, b = map(int, input().split())
    songs.append((a, b))

initial_sum = sum([item[0] for item in songs])

if sum([item[1] for item in songs]) > m:
    print('-1')
elif initial_sum <= m:
    print('0')
else:
    compressed_sum = 0
    temp_sum = 0
    songs = sorted(songs, key=lambda x: x[0] - x[1], reverse=True)
    for i in range(len(songs)):
        compressed_sum += songs[i][1]
        temp_sum += songs[i][0]
        if compressed_sum + (initial_sum - temp_sum) <= m:
            print(i+1)
            break
