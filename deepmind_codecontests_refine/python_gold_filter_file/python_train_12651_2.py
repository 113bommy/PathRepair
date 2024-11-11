__author__ = 'Alexandret'

likes_amount = int(input())
photo_rating = dict()

likes = input().split(' ')
current_chemp = -1
current_chemp_res = -1
for photo_id in likes:
    # print(photo_id)
    if photo_id in photo_rating:
        photo_rating[photo_id] += 1
    else:
        photo_rating[photo_id] = 1
    if photo_rating[photo_id] > current_chemp_res:
        current_chemp = photo_id
        current_chemp_res = photo_rating[photo_id]
print(current_chemp)