"""
file = input('Введите имя html-версии страницы вк\nс прогруженной музыкой: ')
artists=[]
songs=[]
c = 0
with open(file) as file:
    for line in file:
        if '<div onmouseover="setTitle(this)" class="audio_row__performers">' in line:
            c += 1
            ind = 0
            artist=''
            while '</a>' in line[ind:]:
                if artist != '':
                    artist += ', '
                temp = line.index('</a>', ind)
                artist += line[line.rindex('>', 0, temp) + 1 : temp]
                ind = temp + 1
            artists.append(artist)
        elif '<span class="audio_row__title_inner _audio_row__title_inner">' in line:
            temp = line.index('</span>')
            songs.append(line[line.rindex('>', 0, temp) + 1 : temp])
n = len(artists)
m = len(str(n))
assert n == len(songs)
print(f'\nTotal: {n}\n')
print('\n\n'.join(f'{str(i + 1).ljust(m)} {artists[i]}\n' + ' ' * (m + 1) + songs[i] for i in range(n)))
"""
for _ in range(int(input())):
    abc=tuple(int(i) for i in input().split())
    print((0,"NO","YES\n{0} {1} {1}".format(max(abc),min(abc)),"YES\n{0} {0} {0}".format(abc[0]))[abc.count(max(abc))])
          
