import sys

chapters = int(sys.stdin.readline().strip())
chapter_pages = list()
for i in range(1, chapters + 1):
    l, r = sys.stdin.readline().split()
    chapter_pages.append((l, r))
read_page = int(sys.stdin.readline().strip())

for index, chapter in enumerate(chapter_pages):
    if int(chapter[0]) <= read_page <= int(chapter[1]):
        print(chapters - index)
        break
else:
    print(1)
