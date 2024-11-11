songs_count, flash = [int(x) for x in input().split()]
songs = []
for _ in range(songs_count):
    a, b = [int(x) for x in input().split()]
    songs.append((a, b, a - b))

songs_sum = sum(song[0] for song in songs)

if songs_sum <= flash:
    print(0)
elif sum(song[1] for song in songs) > flash:
    print(-1)
else:
    zip_count = 0
    w = sorted([x[2] for x in songs], reverse=True)
    delta = songs_sum - flash
    for z in w:
        zip_count += 1
        delta -= z
        if delta <= 0:
            break
    print(zip_count)
