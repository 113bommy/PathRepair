#python3
# utf-8
from collections import Counter

songs_nr, fav_groups_nr = (int(x) for x in input().split())
song_idx___group_idx = [int(x) for x in input().split()]

fav_group_idx___songs_nr = {}
for fav_group_idx in range(1, fav_groups_nr + 1):
    fav_group_idx___songs_nr[fav_group_idx] = 0
for group_idx in song_idx___group_idx:
    if group_idx <= fav_groups_nr:
        fav_group_idx___songs_nr[group_idx] += 1

min_max_value = songs_nr // fav_groups_nr
possib_replacements_nr = 0
for song_idx in range(songs_nr):
    group_idx = song_idx___group_idx[song_idx]
    if group_idx <= fav_groups_nr:
        continue
    possib_replacements_nr += 1
for fav_group_idx, fav_songs_nr in fav_group_idx___songs_nr.items():
    if fav_songs_nr > min_max_value:
        possib_replacements_nr += fav_songs_nr - min_max_value
replacements_nr = 0
while True:
    curr_group_idx = min(fav_group_idx___songs_nr, key=lambda x: fav_group_idx___songs_nr[x])
    if min(fav_group_idx___songs_nr.values()) >= min_max_value:
        break
    elif replacements_nr == possib_replacements_nr:
        break
    for song_idx in range(songs_nr):
        group_idx = song_idx___group_idx[song_idx]
        if group_idx > fav_groups_nr:
            replacements_nr += 1
            song_idx___group_idx[song_idx] = curr_group_idx
            fav_group_idx___songs_nr[curr_group_idx] += 1
            break
        elif fav_group_idx___songs_nr[group_idx] > min_max_value:
            replacements_nr += 1
            song_idx___group_idx[song_idx] = curr_group_idx
            fav_group_idx___songs_nr[group_idx] -= 1
            fav_group_idx___songs_nr[curr_group_idx] += 1
            break
print(min_max_value, replacements_nr)
print(*song_idx___group_idx)
